/*=========================================================================
  Program:   OsiriX

  Copyright (c) OsiriX Team
  All rights reserved.
  Distributed under GNU - LGPL
  
  See http://www.osirix-viewer.com/copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.
 ---------------------------------------------------------------------------
 
 This file is part of the Horos Project.
 
 Current contributors to the project include Alex Bettarini and Danny Weissman.
 
 Horos is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation,  version 3 of the License.
 
 Horos is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Horos.  If not, see <http://www.gnu.org/licenses/>.

 

 
 ---------------------------------------------------------------------------
 
 This file is part of the Horos Project.
 
 Current contributors to the project include Alex Bettarini and Danny Weissman.
 
 Horos is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation,  version 3 of the License.
 
 Horos is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Horos.  If not, see <http://www.gnu.org/licenses/>.

=========================================================================*/

#import <Cocoa/Cocoa.h>
#import "DCMView.h"
#import "CPRMPRDCMView.h"

enum _CPRTransverseViewReformationDisplayStyle { 
    CPRTransverseViewStraightenedReformationDisplayStyle = 0,
    CPRTransverseViewStretchedReformationDisplayStyle = 1,
};
typedef NSInteger CPRTransverseViewReformationDisplayStyle;

// horrible name! rename me!
enum _CPRTransverseViewSectionType { 
    CPRTransverseViewNoneSectionType = -1,
    CPRTransverseViewCenterSectionType = 0,
    CPRTransverseViewLeftSectionType,
    CPRTransverseViewRightSectionType
};
typedef NSInteger CPRTransverseViewSection;

@class CPRCurvedPath;
@class CPRDisplayInfo;
@class CPRVolumeData;
@class CPRObliqueSliceGeneratorRequest;
@class StringTexture;

@interface CPRTransverseView : DCMView {
    id<CPRViewDelegate> _delegate;

    CPRCurvedPath *_curvedPath;
    CPRDisplayInfo *_displayInfo;
    CPRTransverseViewSection _sectionType;
    CGFloat _sectionWidth;
    
    CPRVolumeData *_volumeData;
    CPRVolumeData *_generatedVolumeData;
    
    CPRObliqueSliceGeneratorRequest *_lastRequest;
    BOOL _processingRequest;
    BOOL _needsNewRequest;
	
	BOOL displayCrossLines;
	CPRTransverseViewReformationDisplayStyle _reformationDisplayStyle;
    
	CGFloat _renderingScale;
	
	float previousScale;
	
	NSMutableDictionary *stanStringAttrib;
	StringTexture *stringTex;
}

@property (nonatomic, readwrite, assign) id<CPRViewDelegate> delegate;
@property (nonatomic, readwrite, copy) CPRCurvedPath* curvedPath;
@property (nonatomic, readwrite, copy) CPRDisplayInfo *displayInfo;
@property (nonatomic, readwrite, assign) CPRTransverseViewSection sectionType;
@property (nonatomic, readwrite, assign) CGFloat sectionWidth; // the width to be displayed in mm
@property (nonatomic, readwrite, retain) CPRVolumeData *volumeData;
@property (nonatomic, readwrite, assign) CGFloat renderingScale;
@property (nonatomic, readwrite, assign) BOOL displayCrossLines;

@property (nonatomic, readwrite, assign) CPRTransverseViewReformationDisplayStyle reformationDisplayStyle;

- (float) pixelsPerMm;

@end
