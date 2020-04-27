app.controller('BookController', ['$scope', '$routeParams', 'books', function($scope, $routeParams, books) {
    books.success(function (data) {
        $scope.book = data[$routeParams.bookId];
    })
    // Using this property to create the URL in line 9 of views/book.html
    $scope.currentBookIndex = parseInt($routeParams.bookId);

}]);
