//
// RemotePhotoTool - remote camera control software
// Copyright (C) 2008-2014 Michael Fink
//
/// \file ImageProperty.cpp Canon control - Image property
//

// includes
#include "stdafx.h"
#include "ImageProperty.hpp"
#include "CdsdkImagePropertyAccess.hpp"
#include "EdsdkPropertyAccess.hpp"
#include "PsrecPropertyAccess.hpp"

CString ImageProperty::Name() const throw()
{
   switch(m_enSDKVariant)
   {
   case variantCdsdk: return CDSDK::ImagePropertyAccess::NameFromId(m_uiImageProperty);
   case variantEdsdk: return EDSDK::PropertyAccess::NameFromId(m_uiImageProperty);
   case variantPsrec: return PSREC::PropertyAccess::NameFromId(static_cast<prUInt16>(m_uiImageProperty & 0xFFFF));
   default:
      ATLASSERT(false);
      return CString(_T("???"));
   }
}

CString ImageProperty::AsString() const throw()
{
   return ValueAsString(m_value);
}

CString ImageProperty::ValueAsString(Variant value) const throw()
{
   try
   {
      switch(m_enSDKVariant)
      {
      case variantCdsdk: return CDSDK::ImagePropertyAccess::DisplayTextFromIdAndValue(m_uiImageProperty, value);
      case variantEdsdk: return EDSDK::PropertyAccess::DisplayTextFromIdAndValue(m_uiImageProperty, value);
      case variantPsrec: return PSREC::PropertyAccess::DisplayTextFromIdAndValue(static_cast<prUInt16>(m_uiImageProperty & 0xFFFF), value);
      default:
         ATLASSERT(false);
         return CString(_T("???"));
      }
   }
   catch(const CameraException& ex)
   {
      return CString(_T("exception during value formatting: ") + ex.Message());
   }
}