'use strict';

describe('Controller: CodeeasyCtrl', function () {

  // load the controller's module
  beforeEach(module('yeomanFunApp'));

  var CodeeasyCtrl,
    scope;

  // Initialize the controller and a mock scope
  beforeEach(inject(function ($controller, $rootScope) {
    scope = $rootScope.$new();
    CodeeasyCtrl = $controller('CodeeasyCtrl', {
      $scope: scope
      // place here mocked dependencies
    });
  }));

  it('should attach a list of awesomeThings to the scope', function () {
    expect(CodeeasyCtrl.awesomeThings.length).toBe(3);
  });
});
