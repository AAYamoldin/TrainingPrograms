'use strict';

/**
 * @ngdoc overview
 * @name yeomanFunApp
 * @description
 * # yeomanFunApp
 *
 * Main module of the application.
 */
angular
  .module('yeomanFunApp', [
    'ngAnimate',
    'ngCookies',
    'ngResource',
    'ngRoute',
    'ngSanitize',
    'ngTouch'
  ])
  .config(function ($routeProvider) {
    $routeProvider
      .when('/', {
        templateUrl: 'views/main.html',
        controller: 'MainCtrl',
        controllerAs: 'main'
      })
      .when('/about', {
        templateUrl: 'views/about.html',
        controller: 'AboutCtrl',
        controllerAs: 'about'
      })
      .when('/codeeasy', {
        templateUrl: 'views/codeeasy.html',
        controller: 'CodeeasyCtrl',
        controllerAs: 'codeeasy'
      })
      .otherwise({
        redirectTo: '/'
      });
  });
