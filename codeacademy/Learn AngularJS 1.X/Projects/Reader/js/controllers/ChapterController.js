app.controller('ChapterController', ['$scope', 'books', '$routeParams', function($scope, books, $routeParams) {
    books.success(function(data) {
        $scope.chapter = data[$routeParams.bookId].chapters;
        //console.log($scope.chapter);
        $scope.book = data[$routeParams.bookId];
        //console.log($scope.book);
        // If there no more chapters left, go back to the bookshelf view
        if($routeParams.chapterId >= $scope.book.chapters.length - 1) {
            $scope.nextChapterIndex = "#";
        }
    });

    // Using these properties to create the URLs in line 1 and line 11 of view/chapter.html
    $scope.currentBookIndex = parseInt($routeParams.bookId);
    $scope.currentChapterIndex = parseInt($routeParams.chapterId);
    $scope.nextChapterIndex = $scope.currentChapterIndex + 1;
}]);
