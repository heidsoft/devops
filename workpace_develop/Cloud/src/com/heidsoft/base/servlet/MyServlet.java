package com.heidsoft.base.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/*
 * 继承httpservlet，并重写do*方法
 */
public class MyServlet extends HttpServlet
{

    
    /**
     * 
     */
     
    private static final long serialVersionUID = 1L;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
	    throws ServletException, IOException
    {
	// TODO Auto-generated method stub
	super.doGet(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
	    throws ServletException, IOException
    {
	// TODO Auto-generated method stub
	super.doPost(req, resp);
    }

    @Override
    public void service(ServletRequest arg0, ServletResponse arg1)
	    throws ServletException, IOException
    {
	// TODO Auto-generated method stub
	super.service(arg0, arg1);
    }
    
    

}
