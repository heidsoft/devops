package com.heidsoft.base.action;

import java.io.ByteArrayInputStream;
import java.io.InputStream;

import com.opensymphony.xwork2.Action;

public class TestAjaxLoginAction implements Action
{
    //封装请求的参数
    private String user;
    private String pass;
    
    //封装结果输出的二进制流
    private InputStream inputStream;
    
    
    
    public String getUser()
    {
        return user;
    }



    public void setUser(String user)
    {
        this.user = user;
    }



    public String getPass()
    {
        return pass;
    }



    public void setPass(String pass)
    {
        this.pass = pass;
    }

    

    public InputStream getInputStream()
    {
        return inputStream;
    }



    public String execute() throws Exception
    {
	System.out.println("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
//	inputStream=user.equals("liubin")&&pass.equals("liubin")
//		?new ByteArrayInputStream("恭喜你，登录成功".getBytes("UTF-8"))
//		:new ByteArrayInputStream("对不起，用户名、密码不匹配".getBytes("UTF-8"));
//		 System.out.println("inputStream="+inputStream);
		return SUCCESS;
    }

}
