//
// RemotePhotoTool - remote camera control software
// Copyright (C) 2008-2017 Michael Fink
//
/// \file PhotomatixInterface.hpp Interface to Photomatix HDR image creation software
//
#pragma once

// includes
#include <vector>
#include "ExternalApplicationInterface.hpp"

/// interface to Photomatix application
class PhotomatixInterface : private ExternalApplicationInterface
{
public:
   /// ctor
   PhotomatixInterface(const CString& cszInstallPath);

   // properties

   /// install path; ends with a trailing backslash
   CString InstallPath() const { return m_cszInstallPath; }

   // methods

   /// returns if hugin is installed on this machine
   bool IsInstalled() const { return !m_cszInstallPath.IsEmpty(); }

   /// runs Photomatix UI with given images
   void RunUI(const std::vector<CString>& imageFilenamesList);

private:
   /// detects photomatix install path
   void Detect();

private:
   /// hugin install path
   CString m_cszInstallPath;
};
