describe("pow", function() {
  it("возводит в степень n", function() {
    assert.equal(pow(2, 3), 8);
  });

   it("для отрицательных n возвращает NaN", function() {
    assert.isNaN(pow(2, -1));
  });

  it("для дробных n возвращает NaN", function() {
    assert.isNaN(pow(2, 1.5));
  });


});
