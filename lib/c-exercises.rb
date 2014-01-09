# -*- coding: utf-8 -*-

require 'rdiscount'
require 'erubis'

require 'sinatra/base'

require 'sinatra/static_assets'
require 'sinatra/filler'

module WB
  class CExercises < Sinatra::Base
    register Sinatra::StaticAssets

    # disable overriding public and views dirs
    set :app_file, __FILE__
    set :static, true

    set :erb, :pattern => '\{% %\}', :trim => true
    set :markdown, :layout => false

    set :logging, true  # use Rack::CommonLogger

    helpers Sinatra::Filler

    get '/' do
      erb(markdown(:main))
    end

    get '/:section' do
      erb(markdown(:"#{params[:section]}"))
    end


    # prettyprint file contents located in 'doc' directory

    get %r{^([-_\w\/]+)\/([-_\w]+)\.((\w{1,4})(\.\w{1,4})?)$} do

      translate = { # to coderay syntax names
        'html.erb' => 'erb',
        'text.erb' => 'text',
        'erb' => 'erb',
        'rb' => 'ruby',
        'ru' => 'ruby',
        'js' => 'javascript',
        'yml' => 'yaml',
        'sql' => 'sql',
        'json' => 'json',
        'c' => 'c',
        'h' => 'c',
        'sh' => 'bash'
      }

      content_type 'text/html', :charset => 'utf-8'

      dirname = params[:captures][0]
      name = params[:captures][1]
      extname = params[:captures][2]
      filename = name + "." + extname

      @title = dirname.split('/').join(' » ')

      @filename = File.expand_path(File.join(settings.root, 'public/doc', dirname, filename))
      # puts STDERR, @filename

      lang = translate[extname] || 'plain_text'

      if File.exists?(@filename) && File.readable?(@filename)
        content = "<h1>#{filename}</h1>"
        content += "<pre><code>:::#{lang}\n#{escape_html(File.read @filename)}</code></pre>"
      else
        content  = "<h2> oops! couldn't find <em>#{filename}</em></h2>"
      end

      erb content, :layout => :code
    end

    not_found do
      'This is nowhere to be found.'
    end

    error do
      'Sorry there was a nasty error – ' + env['sinatra.error'].name
    end

  end
end
