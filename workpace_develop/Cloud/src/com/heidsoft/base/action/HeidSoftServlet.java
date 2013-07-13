package com.heidsoft.base.action;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class HeidSoftServlet extends HttpServlet
{   
    private static final long serialVersionUID = -4929958545028296515L;
    
    
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
	    throws ServletException, IOException
    {
	System.out.println("servlet 测试"+req.getProtocol());
	System.out.println("servlet 请求端口:"+req.getLocalPort());
	
	resp.getWriter().print("HelloServlet测试 ");
    }

    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
	    throws ServletException, IOException
    {
	doGet(req, resp);
    }

 

}
