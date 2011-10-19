#pragma once
#include "mptrack.h"
#include "MainFrm.h"
#include "VstPlug.h"
#include "abstractvsteditor.h"

enum
{
	PARAM_RESOLUTION = 1000,
	NUM_PLUGINEDITOR_PARAMETERS = 8,	// Parameters on screen
};

#ifndef NO_VST

//====================
class ParamControlSet
//====================
{
protected:
	CSliderCtrl valueSlider;
	CEdit valueEdit;
	CStatic nameLabel;
	CStatic valueLabel;
	CStatic perMilLabel;

public:
	ParamControlSet(CWnd *parent, const CRect &rect, int setID);
	~ParamControlSet();

	void EnableControls(bool enable = true);
	void ResetContent();

	void SetParamName(const CString &name);
	void SetParamValue(int value, const CString &text);

	int GetParamValueFromSlider() const;
	int GetParamValueFromEdit() const;

	int GetSliderID() const { return valueSlider.GetDlgCtrlID(); };
};


//=================================================
class CDefaultVstEditor : public CAbstractVstEditor
//=================================================
{
protected:

	vector<ParamControlSet *> controls;

	CScrollBar paramScroller;
	PlugParamIndex paramOffset;

	int m_nControlLock;

public:

	CDefaultVstEditor(CVstPlugin *pPlugin);
	virtual ~CDefaultVstEditor();

	void UpdateParamDisplays() { UpdateControls(false); };

	virtual void OnOK();
	virtual void OnCancel();
	BOOL OpenEditor(CWnd *parent);
	void DoClose();
	afx_msg void OnClose();

protected:

	virtual void DoDataExchange(CDataExchange* pDX);
	
	DECLARE_MESSAGE_MAP()

	afx_msg void OnParamTextboxChanged(UINT id);
	afx_msg void OnParamSliderChanged(UINT id);

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);

protected:

	void CreateControls();
	void UpdateControls(bool updateParamNames);
	void SetParam(PlugParamIndex param, int value);
	void UpdateParamDisplay(PlugParamIndex param);

};

#endif // NO_VST

