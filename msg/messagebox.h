/**
  *  @brief    自定义MessageBox
  *  @file     messagebox.h
  */
#ifndef _CUSTOM_MESSAGEBOX_H_
#define _CUSTOM_MESSAGEBOX_H_

#include <QtGui>
#include <QDialog>
#include <QLabel>
#include <QToolButton>
#include <QPixmap>
#include <QFont>
#include <QHBoxLayout>
#include <QVBoxLayout>
/**
 * @brief 自定义消息提示框类
 */
class CustomMessageBox : public QDialog
{
    Q_OBJECT
public:

    /**
     * @brief 自定义枚举类型 消息的类型
     */

    enum CUSTOM_MESSAGE_TYPE{
        CUSTOM_MESSAGE_NOICON = 0,    /** 无 */
        CUSTOM_MESSAGE_CONFIRM,       /** 确认*/
        CUSTOM_MESSAGE_QUESTION,      /** 询问 */
        CUSTOM_MESSAGE_INFORMATION,   /** 信息 */
        CUSTOM_MESSAGE_WARNING,       /** 警告 */
        CUSTOM_MESSAGE_CRITICAL,      /** 错误 */
    };

    /**
     * @brief 构造函数
     * @param type [in] 消息类型
     * @param strTitle [in]标题
     * @param strInfo [in] 消息内容
     * @param parent [in] 父类窗口
     * @param flags [in] 窗口标志
     */
    CustomMessageBox(CUSTOM_MESSAGE_TYPE type, const QString &strTitle, const QString &strInfo,QWidget *parent = 0,
                     Qt::WindowFlags flags = Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    ~CustomMessageBox();
    /**
     * @brief 双屏在副屏显示
     *
     */
    void setIsDoubleScreen();

    /**
     * @brief 设置显示内容
     * @param strInfo [in] 信息内容
     */
    void setTextInfo(const QString &strInfo);

    /**
     * @brief 这是一个重载函数
     * @see CustomMessageBox::setTextInfo
     * @param strTitle [in] 标题
     * @param strInfo [in] 信息内容
     */
    void setTextInfo(const QString &strTitle, const QString &strInfo);

    /**
     * @brief 这是一个重载函数
     * @see CustomMessageBox::setTextInfo
     * @param type[in] 消息的类型
     * @param strTitle [in] 标题
     * @param strInfo [in] 信息内容
     */
    void setTextInfo(CUSTOM_MESSAGE_TYPE type, const QString &strTitle, const QString &strInfo);

private:
    /**
     * @brief 初始化
     * @param strInfo [in] 信息内容
     */
    void initialize(const QString &strInfo);

    /**
     * @brief 布局
     */
    void alignment();

private:
    QLabel *m_pLabelIcon;  /** 提示信息类型图标 */
    QLabel *m_pLabelInfo;  /** 提示信息 */
    QToolButton *m_pBtnYes; /** 是（确定）按扭 */
    QToolButton *m_pBtnNo;  /** 否（取消）按扭 */
    CUSTOM_MESSAGE_TYPE m_eCustomType; /** 自定义类型  */
 };

#endif //_CUSTOM_MESSAGEBOX_H_
