require 'rubygems'
require 'nokogiri'
require 'open-uri'

# source = "http://nms.lu.lv/goda-plaksne/kopvertejuma-labakie/"
source = "http://nms.lu.lv/skolenu-ranga-tabula-2011-12-m-g/"
page  = Nokogiri::HTML(open(source).read)
# p page.class
# p page
# p page.css('td')[1] # should return an array of 4 table cell nodes
# a = page.xpath("/html/body/table/tr[1]").text
# p a
rows = page.xpath('//table/tbody/tr[position() > 1]')
for r in rows
	p r.xpath('td')[1].text
end
# rows.xpath('td').map {|td| td.text}
# p rows