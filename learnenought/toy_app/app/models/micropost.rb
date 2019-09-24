class Micropost < ApplicationRecord
  belongs_to :user
validates :content, length: { maximum: 140, minimum: 1}
end


