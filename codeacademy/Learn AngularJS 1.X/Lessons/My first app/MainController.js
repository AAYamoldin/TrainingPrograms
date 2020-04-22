app.controller('MainController', ['$scope', function($scope){
    $scope.title = 'Hello AAYamoldin!';
    $scope.promo = 'Go away CoViD-19';
    $scope.products = [
        {
            name: 'The Book of Trees',
            price: 19,
            pubdate: new Date('2014', '03', '08'),
            cover: 'img/the-book-of-trees.jpg',
            likes: 0,
            dislikes: 0
        },
        {
            name: 'Program or be Programmed',
            price: 8,
            pubdate: new Date('2013', '08', '01'),
            cover: 'img/program-or-be-programmed.jpg',
            likes: 0,
            dislikes: 0
        },
        {
            name: 'War and Peace',
            price: 100,
            pubdate: new Date('1873'),
            cover: '',
            likes: 0,
            dislikes: 0
        },
        {
            name: 'lol and kek',
            price: 1000,
            pubdate: new Date('2020', '04', '21'),
            cover: '',
            likes: 0,
            dislikes: 0
        }
    ];
    $scope.plusOne = function(index) {
        $scope.products[index].likes += 1;
    };
    $scope.minusOne = function(index) {
        $scope.products[index].dislikes += 1;
    };
}]);