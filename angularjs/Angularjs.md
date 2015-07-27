```

AngularJS 在幕后会为你在 scope 模型上设置一个 watcher ，它用来在数据发生变化的时候更新 view 。这里的 watcher 和你会在 AngularJS 中设置的 watcher 是一样的：

$scope.$watch('aModel', function(newValue, oldValue) {
  //update the DOM with newValue
});
传入到 $watch() 中的第二个参数是一个回调函数，该函数在 aModel 的值发生变化的时候会被调用。

$digest 循环中， watchers 会被触发。当一个 watcher 被触发时， AngularJS 会检测 scope 模型，如何它发生了变化那么关联到该 watcher 的回调函数就会被调用。
那么，下一个问题就是 $digest 循环是在什么时候以各种方式开始的？

```