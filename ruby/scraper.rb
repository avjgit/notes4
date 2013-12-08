require 'rubygems'
require 'nokogiri'
require 'open-uri'

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

# p ratings_per_year
p ratings_all