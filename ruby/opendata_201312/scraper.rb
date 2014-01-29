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

all_years_ratings = Hash.new
total_ratings = Hash.new 0

# 1982..2011
for year in 1982..2011

    page  = Nokogiri::HTML(open(source(source_template, year)).read)
    one_year_ratings = Hash.new 0

    schools = page.xpath('//table/tbody/tr[position() > 1]')
    for row in schools
        school =  row.xpath('td')[1].text
        points =  row.xpath('td')[2].text.to_i rescue points = 0

        if !one_year_ratings.has_key?(school)
            rating_points = [1, points]
            one_year_ratings[school] = rating_points
            total_ratings[school] = rating_points
        else
            one_year_ratings[school][0] += 1
            one_year_ratings[school][1] += points
            total_ratings[school][0] += 1
            total_ratings[school][1] += points
        end
    end
    all_years_ratings[year] = one_year_ratings
end

all_years_ratings['total'] = total_ratings

Rating = Struct.new(:year, :school, :count, :points)
ratings = []
ratings << Rating.new('Gads', 'Skola', 'Skoleenu skaits', 'Punkti')

for year in all_years_ratings.keys
    for school in all_years_ratings[year]
        ratings << Rating.new(year, school[0], school[1][0], school[1][1])
    end
end

CSV.open("ratings.csv", "wb") {|csv| ratings.to_a.each {|elem| csv << elem} }