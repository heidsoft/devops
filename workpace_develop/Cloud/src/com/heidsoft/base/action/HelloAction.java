package com.heidsoft.base.action;

import com.opensymphony.xwork2.ActionSupport;

public class HelloAction extends ActionSupport
{
    private static final long serialVersionUID = -2258258951538980751L;

    private String customString="aaaaa";

    public String getCustomString()
    {
	return customString;
    }

    public void setCustomString(String customString)
    {
	this.customString = customString;
    }

    public String execute()
    {
	setCustomString("hello world");
	return SUCCESS;
    }

    public void addActionError(String anErrorMessage)
    {
	String s = anErrorMessage;
	System.out.println(s);
    }

    public void addActionMessage(String aMessage)
    {
	String s = aMessage;
	System.out.println(s);

    }

    public void addFieldError(String fieldName, String errorMessage)
    {
	String s = errorMessage;
	String f = fieldName;
	System.out.println(s);
	System.out.println(f);

    }

}
