require 'bundler/setup'

require 'c-exercises'

require 'coderay'
require 'rack/codehighlighter'

#use Rack::ShowExceptions

use Rack::Codehighlighter, :coderay, :markdown => true, :element => "pre>code"

run WB::CExercises.new
