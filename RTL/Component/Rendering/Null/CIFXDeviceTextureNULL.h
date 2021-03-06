//***************************************************************************
//
//  Copyright (c) 2001 - 2006 Intel Corporation
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
//***************************************************************************
// CIFXDeviceTextureNULL.h
#ifndef CIFX_DEVICE_TEXTURENULL_H
#define CIFX_DEVICE_TEXTURENULL_H

#include "CIFXDeviceTexture.h"

//==============================
// CIFXDeviceTextureNULL
//==============================
class CIFXDeviceTextureNULL : public CIFXDeviceTexture
{
	U32 m_refCount;
public:
	U32 IFXAPI  AddRef ();
	U32 IFXAPI  Release ();
	IFXRESULT IFXAPI  QueryInterface (IFXREFIID interfaceId, void** ppInterface);

	friend IFXRESULT IFXAPI_CALLTYPE CIFXDeviceTextureNULLFactory(IFXREFIID intId, void** ppUnk);

	//====================================
	// CIFXDeviceTextureNULL methods
	//====================================
	IFXRESULT IFXAPI Initialize(CIFXRenderDeviceNULLPtr& spDevice);

protected:
	CIFXDeviceTextureNULL();
	virtual ~CIFXDeviceTextureNULL();
	
	virtual IFXRESULT IFXAPI SetHWRenderFormat(IFXenum eFormat);
	virtual IFXRESULT IFXAPI SetHWTexture();

	virtual IFXRESULT IFXAPI Lock(	IFXenum eType, 
									U32 uMipLevel, 
									STextureOutputInfo& rTex	);

	virtual IFXRESULT IFXAPI Unlock(IFXenum eType, 
									U32 uMipLevel, 
									STextureOutputInfo& rTex	);

	void IFXAPI InitData();

	virtual IFXRESULT IFXAPI Create2DTexture();
	virtual IFXRESULT IFXAPI CreateCubeTexture();

	IFXRESULT IFXAPI Construct();

	CIFXRenderDeviceNULL* m_pDevice;

	U8*  m_pTexture;
	U32	 m_uPitch;
	BOOL m_bNeedsRecreate;
	BOOL m_bInLock;
};
typedef IFXSmartPtr<CIFXDeviceTextureNULL> CIFXDeviceTextureNULLPtr;

#endif // CIFX_DEVICE_TEXTURENULL_H
