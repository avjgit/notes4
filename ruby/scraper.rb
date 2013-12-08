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
points_per_year = Hash.new

ratings_all = Hash.new 0
points_all = Hash.new 0

Rating = Struct.new(:year, :school, :count, :points)
ratings = []
ratings << Rating.new('Gads', 'Skola', 'Vietas', 'Punkti')

# 1982..2011
for year in 1982..2011
    page  = Nokogiri::HTML(open(source(source_template, year)).read)
    
    year_ratings = Hash.new 0
    year_points = Hash.new 0

    schools = page.xpath('//table/tbody/tr[position() > 1]')
    for row in schools
        school =  row.xpath('td')[1].text
        year_ratings[school] += 1
        ratings_all[school] += 1

        if points = row.at_xpath('td')[2]
            points =  points.text
            year_points[school] += points
            points_all[school] += points
        end

    end

    ratings_per_year[year] = year_ratings
    points_per_year[year] = year_points

end

ratings_per_year['total'] = ratings_all
points_per_year['total'] = points_all

for year in ratings_per_year.keys
    for school in ratings_per_year[year]
        r = Rating.new(year, school[0], school[1], points_per_year[year][school][1])
        ratings << r
    end
end
# p ratings_per_year['total']
p ratings
# CSV.open("ratings.csv", "wb") {|csv| ratings_per_year.to_a.each {|elem| csv << elem} }
# CSV.open("ratings.csv", "wb") {|csv| ratings.to_a.each {|elem| csv << elem} }