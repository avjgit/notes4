require 'rubygems'
require 'nokogiri'
require 'open-uri'
require 'csv'

source_template = 'http://nms.lu.lv/skolenu-ranga-tabula-STARTYEAR-ENDYEAR-m-g/'

ratings_per_year = Hash.new
ratings_all = Hash.new 0

for year in 1982..2011

	source = source_template.sub 'STARTYEAR', year.to_s
	
	if (year == 1999) # because of nms webmasters...
		source = source.sub 'ENDYEAR', (year + 1).to_s
	else
		source = source.sub 'ENDYEAR', ((year + 1).to_s)[2..3]
	end
	page  = Nokogiri::HTML(open(source).read)
	
	year_ratings = Hash.new 0
	schools = page.xpath('//table/tbody/tr[position() > 1]')
	for row in schools
		school =  row.xpath('td')[1].text
		year_ratings[school] += 1
		ratings_all[school] += 1
	end
	ratings_per_year[year] = year_ratings

end
ratings_per_year['total'] = ratings_all
Rating = Struct.new(:year, :school, :count)
ratings = []
for year in ratings_per_year.keys
	for school in ratings_per_year[year]
		r = Rating.new(year, school[0], school[1])
		ratings << r
	end
end
# p ratings_per_year['total']
# p ratings
# CSV.open("ratings.csv", "wb") {|csv| ratings_per_year.to_a.each {|elem| csv << elem} }
CSV.open("ratings.csv", "wb") {|csv| ratings.to_a.each {|elem| csv << elem} }