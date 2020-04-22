app.controller('MainController', ['$scope', function($scope) {
    $scope.today = new Date();

    $scope.appetizers = [
        {
            name: 'Caprese',
            description: 'Mozzarella, tomatoes, basil, balsmaic glaze.',
            price: 4.95
        },
        {
            name: 'Mozzarella Sticks',
            description: 'Served with marinara sauce.',
            price: 3.95
        },
        {
            name: 'Bruschetta',
            description: 'Grilled bread garlic, tomatoes, olive oil.',
            price: 4.95
        }
    ];

    $scope.mains = [
        {
            name: 'Borsch',
            description: 'Red soup',
            price: 10
        },
        {
            name: 'Schi',
            description: 'Soup which made of cabbage',
            price: 12
        }
    ];

    $scope.extras = [
        {
            name: 'lol',
            descriptoin: 'Potatos with sosiges',
            price: 0.2
        },
        {
            name: 'kek',
            description: 'bread with nothing',
            price: 0.1
        }
    ];

}]);