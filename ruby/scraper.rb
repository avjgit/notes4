require 'rubygems'
require 'nokogiri'
require 'open-uri'

source = "http://nms.lu.lv/goda-plaksne/kopvertejuma-labakie/"
page  = Nokogiri::HTML(open(source).read)
p page