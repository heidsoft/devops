package com.heidsoft.base.action;

import com.heidsoft.base.vo.User;
import com.opensymphony.xwork2.Action;

public class TestOgnlAction implements Action {
	private User user;
	private String tip;

	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}

	public String getTip() {
		return tip;
	}

	public void setTip(String tip) {
		this.tip = tip;
	}

	public String execute() throws Exception {
		System.out.println("action start!");
		System.out.println("name" + getUser().getName());
		System.out.println("name" + getUser().getPass());
		// 通过user属性的name和pass属性判断控制逻辑
		if (getUser().getName().equals("liubin")
				&& getUser().getPass().equals("liubin")) {

			setTip("转换成功");
			return "success";
		} else {
			setTip("转换失败");
			return "error";
		}

	}

}
