# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)
require "version"

Gem::Specification.new do |s|
  s.name        = "c-exercises"
  s.version     = WB::VERSION
  s.authors     = ["Wlodek Bzyl"]
  s.email       = ["matwb@ug.edu.pl"]
  s.homepage    = ""
  s.summary     = %q{Zadania do wykładu z Języki Programowania.}
  s.description = %q{Zadania do wykładu z Języki Programowania. 2011/2012}

  s.rubyforge_project = "sp"

  s.add_runtime_dependency 'rack'
  s.add_runtime_dependency 'sinatra'
  s.add_runtime_dependency 'rdiscount'
  s.add_runtime_dependency 'erubis'
  s.add_runtime_dependency 'coderay'

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  s.require_paths = ["lib"]
end
