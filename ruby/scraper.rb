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
# points_per_year = Hash.new

ratings_all = Hash.new 0
# points_all = Hash.new 0

Rating = Struct.new(:year, :school, :count, :points)
ratings = []
ratings << Rating.new('Gads', 'Skola', 'Vietas', 'Punkti')

# 1982..2011
for year in 1982..2011

    page  = Nokogiri::HTML(open(source(source_template, year)).read)
    # p 'checking year ' + year.to_s
    
    year_ratings = Hash.new 0
    # year_points = Hash.new 0

    schools = page.xpath('//table/tbody/tr[position() > 1]')
    for row in schools
        school =  row.xpath('td')[1].text
        # year_ratings[school] += 1
        # ratings_all[school] += 1

        points =  row.xpath('td')[2].text.to_i rescue points = 0
        # # p 'points for ' + school + ' found: ' + points.to_s
        # year_points[school] += points.to_i
        # points_all[school] += points.to_i


        if !year_ratings.has_key?(school)
            rating_points = [1, points]
            year_ratings[school] = rating_points
            # year_ratings[school][0] = 1
            # year_ratings[school][1] = 50
        else
            year_ratings[school][0] += 1
            year_ratings[school][1] += points
        end

        if !ratings_all.has_key?(school)
            rating_points = [1, points]
            ratings_all[school] = rating_points
            # year_ratings[school][0] = 1
            # year_ratings[school][1] = 50
        else
            ratings_all[school][0] += 1
            ratings_all[school][1] += points
        end
        # ratings_all[school] += 1

        # points =  row.xpath('td')[2].text rescue points = 0
        # # p 'points for ' + school + ' found: ' + points.to_s
        # year_points[school] += points.to_i
        # points_all[school] += points.to_i

        


    end

    ratings_per_year[year] = year_ratings
    # points_per_year[year] = year_points

end

ratings_per_year['total'] = ratings_all
# points_per_year['total'] = points_all

# p points_per_year['total']
# py = points_per_year[2011]
# p py
# p ratings_per_year['total']
# p py["Preiļu Valsts ģimnāzija"]
# p py["Daugavpils Krievu vidusskola – licejs"]

for year in ratings_per_year.keys
    for school in ratings_per_year[year]
        # p school
#         year_pp = points_per_year[year]
#         # p year_pp

#         year_school_pp = year_pp[school]
#         # p year_school_pp


        r = Rating.new(year, school[0], school[1][0], school[1][1])
        ratings << r
    end
end

# p ratings_per_year['total']
p ratings
# CSV.open("ratings.csv", "wb") {|csv| ratings_per_year.to_a.each {|elem| csv << elem} }
CSV.open("ratings.csv", "wb") {|csv| ratings.to_a.each {|elem| csv << elem} }