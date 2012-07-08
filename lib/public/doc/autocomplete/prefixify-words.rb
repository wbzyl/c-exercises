# -*- coding: utf-8 -*-
#
# http://antirez.com/post/autocomplete-with-redis.html
#
# What we do is the following: instead of adding only full words to
# the sorted set, we add also all the possible prefixes of any given
# word. We also need a way to distinguish actual words from
# prefixes. So this is what we do:

# 1. For every word, like "bar", we add all the prefixes: "b", "ba", "bar".
# 2. For every word we finally add the word itself but with a trailing "*" character,

require "ansi/code"
include ANSI::Code

if !ARGV[0]
  puts "#{ bold{ "Użycie: " }} ruby prefixify-words.rb female-names.txt | sort -u"
  exit 1
end

File.new(ARGV[0]).each_line do |word|
  next if word.match /^\#/
  word.strip!
  len = word.length
  (1..len).each do |n|
    prefix = word[0...n]
    puts prefix
  end
  puts "#{word}*"
end
