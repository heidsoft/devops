package com.heidsoft.base.action;

import java.util.HashMap;
import java.util.Map;

import org.apache.struts2.json.annotations.JSON;

import com.opensymphony.xwork2.Action;

public class JSONExample implements Action {
	// 模拟处理结果的属性
	private int[] ints = { 10, 20 };
	private Map<String, String> map = new HashMap<String, String>();
	private String customName = "顾客";

	// 封装请求的三个参数
	private String field1;
	// “transient”修饰的属性不会被序列化
	private transient String field2;
	// 没有setter和getter方法的字段不会被序列化
	private String field3;

	public String execute() throws Exception {
		System.out.println("uuuuuuuuuuuuuuuuu");
		map.put("name", "刘彬");
		return SUCCESS;
	}

	// 使用注释语法来给变该属性序列化的属性名
	@JSON(name = "newName")
	public Map getMap() {
		return this.map;
	}

	// customName属性的setter和getter方法
	public String getCustomName() {
		return customName;
	}

	public void setCustomName(String customName) {
		this.customName = customName;
	}

	public String getField1() {
		return field1;
	}

	public void setField1(String field1) {
		this.field1 = field1;
	}

	public String getField2() {
		return field2;
	}

	public void setField2(String field2) {
		this.field2 = field2;
	}

	public String getField3() {
		return field3;
	}

	public void setField3(String field3) {
		this.field3 = field3;
	}

}
