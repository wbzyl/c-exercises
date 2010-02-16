require 'rake'

$LOAD_PATH.unshift('lib')

begin
  require 'jeweler'
  Jeweler::Tasks.new do |gemspec|
    gemspec.name         = "c-exercises"
    gemspec.summary      = "Zadania do wykladu Jezyki Programowania."    
    gemspec.email        = "matwb@ug.edu.pl"
    gemspec.authors      = ["Wlodek Bzyl"]
    gemspec.homepage     = "http://github.com/wbzyl/c-exercises"

    gemspec.description = <<-EOF
Zadania do wykladu Jezyki Programowania
    EOF
    
    gemspec.files = FileList['lib/**/*', "Rakefile", "VERSION.yml"]

    gemspec.add_runtime_dependency 'rack' 
    gemspec.add_runtime_dependency 'sinatra'
    gemspec.add_runtime_dependency 'rdiscount'
    gemspec.add_runtime_dependency 'ultraviolet'
    gemspec.add_runtime_dependency 'rack-codehighlighter'
    gemspec.add_runtime_dependency 'sinatra-rdiscount'    
    gemspec.add_runtime_dependency 'sinatra-static-assets'
  end
  Jeweler::GemcutterTasks.new  
rescue LoadError
  puts "Jeweler not available."
  puts "Install it with:"
  puts "  sudo gem install jeweler"
end
