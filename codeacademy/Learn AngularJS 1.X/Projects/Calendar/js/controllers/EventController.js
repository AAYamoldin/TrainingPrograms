app.controller('EventController', ['$scope', '$routeParams','events', function($scope, $routeParams, events) {
    events.success(function(data){
        $scope.event = data.events[$routeParams.id];
    });
}]);