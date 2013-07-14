package com.heidsoft.base.action;

import java.util.Map;

import com.heidsoft.base.vo.User;
import com.opensymphony.xwork2.Action;

public class TestMapOgnlAction implements Action
{
    private Map<String,User> users;
    private String tip;
    
    
    public Map<String, User> getUsers()
    {
        return users;
    }


    public void setUsers(Map<String, User> users)
    {
        this.users = users;
    }


    public String getTip()
    {
        return tip;
    }


    public void setTip(String tip)
    {
        this.tip = tip;
    }


    public String execute() throws Exception
    {
	//输出前端传入的map users
	System.out.println(getUsers());
	if(getUsers().get("one").getName().equals("liubin")&&
		getUsers().get("one").getPass().equals("liubin"))
	{
	    System.out.println("成功");
	    return SUCCESS;
	}
	else
	{
	    System.out.println("失败");
	    return ERROR;
	}
    }

}
