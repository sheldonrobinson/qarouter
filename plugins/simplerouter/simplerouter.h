/*******************************************************************************
* Copyright (C) Pike Aerospace Research Corporation                            *
* Author: Mike Sharkey <mike@pikeaero.com>                                     *
*******************************************************************************/
#ifndef SIMPLEROUTER_H
#define SIMPLEROUTER_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QList>
#include <QRectF>
#include <QStack>
#include <QMap>
#include <cplugininterface.h>

class CPcb;
class CPcbNet;
class CGSegment;
class SimpleRouter : public QObject, public CPluginInterface
 {
	Q_OBJECT
	Q_INTERFACES(CPluginInterface)

	public:
		friend class CSegmentState;

		virtual tPluginType			type();							/* is the a router or post-router */

		virtual QString				title() const;					/* a brief name for the plugin */
		virtual QString				version() const;				/* return a version number string */
		virtual QStringList			credits() const;				/* name of authors + email */
		virtual QString				website() const;				/* the author's website */
		virtual QString				description() const;			/* a brief description of the plugin */
		virtual QStringList			license() const;				/* the license text for the plugin */

		virtual bool				start(CPcb* pcb);				/** initialize, gets' called once prior to exec() being called */
		virtual void				stop();							/** stop processing */
		virtual bool				exec();							/** get's called repeatedly while exec() returns true, return false to stop */
		virtual QString				elapsed();						/** elapsed time of the run in hh:mm:ss format */
	signals:
		void						status(QString txt);			/** emit a status text */
	protected:

		typedef enum {
			Idle,													/** there is nothing happening */
			Selecting,												/** selecting which net(s) to route */
			Routing,												/** committing a route */
		} tRunState;

		static const double dirNone	=	-1.0;	// none
		static const double dirN	=	0.0;	// North
		static const double dirNNE	=	22.5;	// North North East
		static const double dirNE	=	45.0;	// North East
		static const double dirENE	=	67.5;	// East North East
		static const double dirE	=	90;		// East
		static const double dirESE	=	112.5;	// East South East
		static const double dirSE	=	135;	// South East
		static const double dirSSE	=	157.5;	// South South East
		static const double dirS	=	180;	// South
		static const double dirSSW	=	202.5;	// South South West
		static const double dirSW	=	225;	// South West
		static const double dirWSW	=	247.5;	// West South West
		static const double dirW	=	270;	// West
		static const double dirWNW	=	292.5;	// West North West
		static const double dirNW	=	315;	// North West
		static const double dirNNW	=	337.5;	// North North West

		CPcb*						pcb() {return mPcb;}
		tRunState					state();
		bool						running() {return state() != Idle;}
		void						setState(tRunState state);
		QString						currentStatus();				/** a brief status report for the status bar */

		void						selectNet(CPcbNet* net,bool selected);
		void						select();
		void						route();

		void						initializeBox();				/** initialize the expanding box */
		void						expandBox();					/** expand the bounding box */

		QStack<CPcbNet*>&			netStack()	{return mNetStack;}

	private:
		CPcb*						mPcb;
		QDateTime					mStartTime;
		tRunState					mState;
		QStack<CPcbNet*>			mNetStack;						/** the current work stack */
		QRectF						mBoundingBox;					/** the expanding bounding box */
};

#endif // SIMPLEROUTER_H
