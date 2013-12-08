require 'rubygems'
require 'nokogiri'
require 'open-uri'
require 'csv'

source_template = 'http://nms.lu.lv/skolenu-ranga-tabula-STARTYEAR-ENDYEAR-m-g/'

def source(source, year)
    source = source.sub 'STARTYEAR', year.to_s
    if (year == 1999) # because of nms webmasters...
        return source.sub 'ENDYEAR', (year + 1).to_s
    else
        return source.sub 'ENDYEAR', ((year + 1).to_s)[2..3]
    end
end

ratings_per_year = Hash.new
ratings_all = Hash.new 0
Rating = Struct.new(:year, :school, :count, :points)
ratings = []
ratings << Rating.new('Gads', 'Skola', 'Vietas', 'Punkti')

# 1982..2011
for year in 1982..2011

    page  = Nokogiri::HTML(open(source(source_template, year)).read)
    year_ratings = Hash.new 0

    schools = page.xpath('//table/tbody/tr[position() > 1]')
    for row in schools
        school =  row.xpath('td')[1].text
        points =  row.xpath('td')[2].text.to_i rescue points = 0

        if !year_ratings.has_key?(school)
            rating_points = [1, points]
            year_ratings[school] = rating_points
            ratings_all[school] = rating_points
        else
            year_ratings[school][0] += 1
            year_ratings[school][1] += points
            ratings_all[school][0] += 1
            ratings_all[school][1] += points
        end
    end
    ratings_per_year[year] = year_ratings
end

ratings_per_year['total'] = ratings_all

for year in ratings_per_year.keys
    for school in ratings_per_year[year]
        ratings << Rating.new(year, school[0], school[1][0], school[1][1])
    end
end

CSV.open("ratings.csv", "wb") {|csv| ratings.to_a.each {|elem| csv << elem} }