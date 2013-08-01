//
// RemotePhotoTool - remote camera control software
// Copyright (C) 2008-2013 Michael Fink
//
//! \file IPhotoModeViewHost.hpp Interface for host of photo mode views
//
#pragma once

// forward references
class RemoteReleaseControl;
class ImageFileManager;
class ViewFinderImageWindow;
class AppSettings;

/// host interface for photo mode views
class IPhotoModeViewHost
{
public:
   /// dtor
   virtual ~IPhotoModeViewHost() throw() { }

   /// start/stop remote release control
   virtual std::shared_ptr<RemoteReleaseControl> StartRemoteReleaseControl(bool bStart) = 0;

   /// returns application settings
   virtual AppSettings& GetAppSettings() throw() = 0;

   /// returns image file manager
   virtual ImageFileManager& GetImageFileManager() throw() = 0;

   /// returns viewfinder window (or nullptr if not active)
   virtual ViewFinderImageWindow* GetViewfinderWindow() throw() = 0;

   /// sets new status text
   virtual void SetStatusText(const CString& cszText) = 0;
};
