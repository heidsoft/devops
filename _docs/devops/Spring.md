#Spring

##springMVC TEST
###DELETE
```
如果出现该错误，请查看@RequestMapping(value = "/delete/"
要写成如下，如果是根据ID删除
@RequestMapping(value = "/delete/{id}"
否则报如下错误:HTTP-405
Request method 'DELETE' not supported
```

