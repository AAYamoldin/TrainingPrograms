class ApplicationController < ActionController::Base
  protect_from_forgery :exception
def hello
  render html: "Hello, world!!"
end
end
