require 'sinatra'
get '/' do#браузер хочет получить какие-то данные
  erb :index
end

get '/contacts' do
  "gvardeyskaya 32, 326 room"
end

post '/' do#браузер хочет отправить какие-то данные
  @login = params[:aaa]
  @password = params[:bbb]
  if @login == 'admin' && @password == 'secret'
    erb :welcome
    else
  erb :poshel_von
  end
end
