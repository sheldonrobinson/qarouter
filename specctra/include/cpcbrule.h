/*******************************************************************************
* Copyright (C) Pike Aerospace Research Corporation                            *
* Author: Mike Sharkey <mike@pikeaero.com>                                     *
*******************************************************************************/
#ifndef CPCBRULE_H
#define CPCBRULE_H

#include <QObject>
#include <QString>
#include <QRectF>
#include <QPainterPath>

#include "cspecctraobject.h"

class CPcbWidth;
class CPcbRule : public CSpecctraObject
{
	Q_OBJECT
	public:
		CPcbRule(QGraphicsItem *parent = 0);
		virtual ~CPcbRule();

		CPcbWidth*					width();

};

#endif // CPCBRULE_H

