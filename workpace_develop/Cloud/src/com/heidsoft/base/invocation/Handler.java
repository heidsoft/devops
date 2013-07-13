package com.heidsoft.base.invocation;

import java.lang.reflect.Method;

import org.springframework.cglib.proxy.InvocationHandler;

import com.heidsoft.base.service.impl.UserServiceImpl;

/*
 * 动态代理
 */
public class Handler implements InvocationHandler
{

    @Override
    public Object invoke(Object arg0, Method arg1, Object[] arg2)
	    throws Throwable
    {
	System.out.println("Begin...");
	Object result = arg1.invoke(new UserServiceImpl(), arg2);
	System.out.println("End...");
	return null;
    }

}
