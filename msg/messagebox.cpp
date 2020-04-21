#include "messagebox.h"

#define LAYOUT_SPACING  (20)
#define DEFAULT_HEIGHT  (100)
#define DEFAULT_WIDTH	(350)
#define MIN_WEIGHT		(100)
#define MIN_WIDTH		(150)
#define FONT_SIZE	    (14)

CustomMessageBox::CustomMessageBox(CUSTOM_MESSAGE_TYPE type, const QString &strTitle, const QString &strInfo,QWidget *parent, Qt::WindowFlags flags)
    :QDialog(parent, flags), m_eCustomType(type)
{
    initialize(strInfo);
    alignment();
    setWindowTitle(strTitle);
    resize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    setMinimumSize(MIN_WIDTH, MIN_WEIGHT);
}
CustomMessageBox::~CustomMessageBox()
{

}

//设置标签的内容
void CustomMessageBox::setTextInfo(const QString &strInfo)
{
    if(!strInfo.isEmpty())
        m_pLabelInfo->setText(strInfo);
}

void CustomMessageBox::setTextInfo(const QString &strTitle, const QString &strInfo)
{
    if(strTitle.isEmpty())
        this->setWindowTitle(strTitle);

    if(!strInfo.isEmpty())
        m_pLabelInfo->setText(strInfo);
}

void CustomMessageBox::setTextInfo(CUSTOM_MESSAGE_TYPE type, const QString &strTitle, const QString &strInfo)
{
    if(strTitle.isEmpty())
        this->setWindowTitle(strTitle);

    if(!strInfo.isEmpty())
        m_pLabelInfo->setText(strInfo);
    else
        return ;

     m_eCustomType = type;
     QString fileName;
     switch(m_eCustomType)
     {
     case CUSTOM_MESSAGE_CONFIRM:
     {
         fileName = ":/img/confirm.png";
         break;
     }
     case CUSTOM_MESSAGE_QUESTION:
     {
         fileName = ":/img/question.png";
         break;
     }
     case CUSTOM_MESSAGE_INFORMATION:
     {
         fileName = ":/img/information.png";
         break;
     }
     case CUSTOM_MESSAGE_WARNING:
     {
         fileName = ":/img/warning.png";
         break;
     }

     case CUSTOM_MESSAGE_CRITICAL:
     {
         fileName = ":/img/error.png";
         break;
     }
     default:
         break;
     }
     QPixmap iconPix(fileName);
     m_pLabelIcon->setPixmap(iconPix);
}


void CustomMessageBox::initialize(const QString &strInfo)
{
    m_pLabelIcon = new QLabel(this);
    QString fileName;
    switch(m_eCustomType){
    case CUSTOM_MESSAGE_CONFIRM:
    {
        fileName = ":/img/confirm.png";
        break;
    }
    case CUSTOM_MESSAGE_QUESTION:
    {
        fileName = ":/img/question.png";
        break;
    }

    case CUSTOM_MESSAGE_INFORMATION:
    {
        fileName = ":/img/information.png";
        break;
    }
    case CUSTOM_MESSAGE_WARNING:
    {
        fileName = ":/img/warning.png";
        break;
    }
    case CUSTOM_MESSAGE_CRITICAL:
    {
        fileName = ":/img/error.png";
        break;
    }
    default:
        break;
    }

    QPixmap iconPix(fileName);
    m_pLabelIcon->setPixmap(iconPix);
    m_pLabelIcon->setFixedSize(45,45);
    m_pLabelIcon->setObjectName("msgBoxIconLabel");

    QFont font;
    font.setBold(true);
    font.setFamily("Consolas");
    font.setPixelSize(FONT_SIZE);

    m_pLabelInfo = new QLabel(strInfo, this);
    m_pLabelInfo->setWordWrap(true);
        m_pLabelInfo->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        m_pLabelInfo->setFont(font);
    m_pLabelInfo->setObjectName("msgBoxInfoLabel");


    m_pBtnYes = new QToolButton(this);
    QPixmap yesPix(":/img/Yes.png");
    m_pBtnYes->setIcon(yesPix);
    m_pBtnYes->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_pBtnYes->setIconSize(QSize(30, 30));
    m_pBtnYes->setFont(font);
    m_pBtnYes->setObjectName("msgBoxYesBtn");
    m_pBtnYes->setFocusPolicy(Qt::NoFocus);

    if(m_eCustomType == CUSTOM_MESSAGE_QUESTION)
        m_pBtnYes->setText(tr("是"));
    else
        m_pBtnYes->setText(tr("确认"));

    connect(m_pBtnYes, SIGNAL(released()), this, SLOT(accept()));

    if(m_eCustomType == CUSTOM_MESSAGE_QUESTION)
    {
        m_pBtnNo = new QToolButton(this);
        QPixmap noPix(":/img/No.png");
        m_pBtnNo->setIcon(noPix);
        m_pBtnNo->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        m_pBtnNo->setIconSize(QSize(30, 30));
        m_pBtnNo->setText(tr("否") );
        m_pBtnNo->setFont(font);
        m_pBtnNo->setObjectName("msgBoxNoBtn");
        m_pBtnNo->setFocusPolicy(Qt::NoFocus);
        connect(m_pBtnNo, SIGNAL(released()), this, SLOT(reject()));
    }

}
//界面布局
void CustomMessageBox::alignment()
{
    QHBoxLayout *hbLabelLayout = new QHBoxLayout;
    hbLabelLayout->addWidget(m_pLabelIcon);
    hbLabelLayout->addWidget(m_pLabelInfo);

    QHBoxLayout *hbBtnLayout = new QHBoxLayout;
    hbBtnLayout->addStretch();
    hbBtnLayout->addWidget(m_pBtnYes);
    if(m_eCustomType == CUSTOM_MESSAGE_QUESTION){
        hbBtnLayout->addStretch();
        hbBtnLayout->addWidget(m_pBtnNo);
    }
    hbBtnLayout->addStretch();

    QVBoxLayout *vbLayout = new QVBoxLayout;
    vbLayout->addLayout(hbLabelLayout);
    vbLayout->addSpacing(20);
    vbLayout->addLayout(hbBtnLayout);

    this->setLayout(vbLayout);

}
