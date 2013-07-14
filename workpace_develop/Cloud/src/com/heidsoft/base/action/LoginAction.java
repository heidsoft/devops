package com.heidsoft.base.action;

import java.util.Calendar;
import java.util.Date;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

public class LoginAction extends ActionSupport
{  
    private static final long serialVersionUID = 1L;
    private String username;
    private String password;
    
    
    
    public String getUsername()
    {
        return username;
    }



    public void setUsername(String username)
    {
        this.username = username;
    }



    public String getPassword()
    {
        return password;
    }



    public void setPassword(String password)
    {
        this.password = password;
    }


    //action执行
    public String testLoginAction(){
	//获取参数值的方式
	//第一种
	System.out.println("username="+this.getUsername());
	System.out.println("password="+this.getPassword());
	
	//方法二:在Action中使用ActionContext得到parameterMap获取参数:  
        ActionContext context=ActionContext.getContext();
  
        //方法三:在Action中取得HttpServletRequest对象，使用request.getParameter获取参数  
        //HttpServletRequest request = (HttpServletRequest)context.get(ServletActionContext.HTTP_REQUEST);  
//        HttpServletRequest request = ServletActionContext.getRequest();   
//        HttpSession httpSession=request.getSession();
        
        Calendar myCalendar = Calendar().getInstance();
        
        Date date = new Date();
        
//        System.out.println("httpSessionId="+httpSession.getId());
//        System.out.println("httpSessionId LastAccessedTime="+httpSession.getLastAccessedTime());

        return "success";
    }


    private Calendar Calendar()
    {
	// TODO Auto-generated method stub
	return null;
    }



    /*
     * (数据验证方法)
     * @see com.opensymphony.xwork2.ActionSupport#validate()
     * 完成输入验证需要重写validate方法
     */
    @Override
    public void validate()
    {
	//如果用户名为空
	if(getUsername()==null|| getUsername().trim().equals("")){
	    addFieldError("username","必须填写用户");
	}
	
	//当密码为空，或者密码为空字符串是，添加表单校验错误
	if(getPassword()==null|| getPassword().trim().equals(""))
	{
	    addFieldError("password","必须填写密码");
	}
	
    }
    
    
}
