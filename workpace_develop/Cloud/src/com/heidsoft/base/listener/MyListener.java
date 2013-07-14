package com.heidsoft.base.listener;

import java.util.Timer;

import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;

/**
 * 实现servlet监听器 Description: MyListener.java Create on 2013-6-25 下午10:13:42
 * 
 * @author liubin
 * @version 1.0
 */
public class MyListener implements ServletContextListener {
	// private Timer timer=null;//定时器
	// private MyTask task=null; //定义任务
	public void contextDestroyed(ServletContextEvent arg0) {
		// 销毁监听器
		System.out.println("========销毁监听器========");
	}

	public void contextInitialized(ServletContextEvent event) {
		System.out.println("========监听器开始========");
		ServletContext servletContext = event.getServletContext();

		/*
		 * 获取web.xml中context所配置的相关参数的值
		 */
		String initValue1 = servletContext.getInitParameter("name");
		String initValue2 = servletContext.getInitParameter("age");

		System.out.println("initValue1=" + initValue1);
		System.out.println("initValue2=" + initValue2);
	}

}
