require 'sinatra'
get '/' do#браузер хочет получить какие-то данные
  erb :index
end

get '/contacts' do
  @title = 'Contacts'
  @message = "gvardeyskaya 32, 326 room"
  erb :message
end

get '/faq' do
  @title = 'FAQ'
  @message = 'Under construction'
  erb :message
end

get '/something' do
@title = 'Something'
  @message = 'you are lox and pidr'
  erb :message
end

get '/admin' do
  erb :poshel_von
end
post '/admin' do
  @login = params[:login]
  @password = params[:password]

  if @login == 'admin' && @password == 'admin'
    erb :welcome
     @logfile = File.open("./users.txt", "r")
     erb :create
    # @logfile.close
  else
    @title = 'Poshel won!'
    @message = 'wrong login or password'
    erb :message
  end
end

post '/' do#браузер хочет отправить какие-то данные
  @user_name = params[:user_name]
  @phone = params[:phone]
  @date_time = params[:date_time]

  @title = 'Thanks!'
  @message = "Thank you, #{@user_name}! We'll be waiting you at #{@date_time}!"

  f = File.open 'users.txt', 'a'
  f.write "\n User: #{@user_name}, Phone: #{@phone}, Date and time: #{@date_time}"
  f.close

  erb :message
end
