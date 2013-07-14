package com.heidsoft.base.service.impl;

import com.heidsoft.base.service.UserService;

public class UserServiceImpl implements UserService {
	public void register(String username, String password) {
		System.out.println("用户注册名:" + username);
		System.out.println("用户注册密码:" + password);
	}
}
