/*================================================================================================*/
/*
 *	Copyright 2013-2015, 2017, 2019, 2023 Avid Technology, Inc.
 *	All rights reserved.
 *	
 *	CONFIDENTIAL: this document contains confidential information of Avid. Do
 *	not disclose to any third party. Use of the information contained in this
 *	document is subject to an Avid SDK license.
 */

/**	
 *  \file AAX_CEffectGUI_Juce.h
 *
 */
/*================================================================================================*/

#ifndef AAX_CEFFECTGUI_JUCE_H
#define AAX_CEFFECTGUI_JUCE_H


#if AAX_SDK_JUCE_MAJOR_VERSION >= 7
#include "juce_core/juce_core.h"
#include "juce_gui_basics/juce_gui_basics.h"
#else
#include "juce.h"
#endif

#include "AAX_Enums.h"
#include "AAX_CEffectGUI.h"
#include "AAX_JuceCount.h"

//==============================================================================
class AAX_JuceContentView : public juce::Component
                          , public juce::DragAndDropContainer
{
public:
	AAX_JuceContentView ( const juce::Colour & inBackColour, AAX_CEffectGUI * inEffectGUI );
	~AAX_JuceContentView() override;

	void							SetEffectGUI ( AAX_CEffectGUI * inEffectGUI );
	AAX_CEffectGUI *				GetEffectGUI ();
	AAX_IEffectParameters *			GetParameters ();
	AAX_IController *				GetController ();
	AAX_IViewContainer *			GetViewContainer ();
	virtual void					SetViewContainer ( AAX_IViewContainer * inViewContainer ) { mViewContainer = inViewContainer; }
	
	enum ColourIds { backgroundColourId = 0x1005700 };
	
	const juce::Colour getBackgroundColour() const;
	void setBackgroundColour (const juce::Colour& newColour);
	void setBackgroundImage( juce::Image * inImage, bool inResize );
	
	virtual AAX_Result	setControlHighlightInfo ( AAX_CParamID inParameterID, AAX_CBoolean inIsHighlighted, AAX_EHighlightColor inColor ) { return AAX_SUCCESS; }
	virtual AAX_Result	clearControlHighlightInfo () { return AAX_SUCCESS; }

	virtual	AAX_Result	TimerWakeup() { return AAX_SUCCESS; }
	void mouseMove ( const juce::MouseEvent & inMouseEvent ) AAX_OVERRIDE;
	
protected:
	void paint (juce::Graphics& g) AAX_OVERRIDE;
	
private:
	AAX_CEffectGUI *		mEffectGUI;
	AAX_IEffectParameters *	mEffectParameters;
	AAX_IController *		mController;
	AAX_IViewContainer *	mViewContainer;
	juce::Image *			mBackgroundImage;
};

//==============================================================================
class AAX_CEffectGUI_Juce : public AAX_CEffectGUI, public AAX_JuceCount
{
public:
	AAX_CEffectGUI_Juce ();
	~AAX_CEffectGUI_Juce () AAX_OVERRIDE;
	
	AAX_Result 	TimerWakeup() AAX_OVERRIDE;

	static bool	IncrementJuceUseCout ();
	static bool	DecrementJuceUseCout ();
	
protected:
	void		CreateViewContainer () AAX_OVERRIDE;
	void		DeleteViewContainer () AAX_OVERRIDE;

	AAX_Result	GetViewSize ( AAX_Point * oEffectViewSize ) const AAX_OVERRIDE;

	/* Create AAX_JuceContentView component
	 Overwrite this method if you want to create you own content view component
	 or add child components */
	void		CreateViewContents () AAX_OVERRIDE;
	
protected:
	AAX_JuceContentView*	mViewComponent;

public:	
	static juce::TooltipWindow*	sTooltipWindow;
};

#endif // AAX_CEFFECTGUI_JUCE_H
