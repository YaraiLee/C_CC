#pragma once

/************************************************************************/
/* 接口类
1.最好不要有成员变量，但可以有静态常量（static const或enum）
2.要有纯虚接口方法
3.要有虚析构函数，并提供默认实现,没有会有内存泄漏可能
4.不要声明构造函数
/************************************************************************/
class CanShoot
{
public:
	static const int START = 1;
	enum {
		MONDAY = 1,
		TUESDAY,
	};
	virtual void aim() = 0;
	virtual void reload() = 0;
	virtual ~CanShoot(){}
};