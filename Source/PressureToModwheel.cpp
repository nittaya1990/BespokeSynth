/**
    bespoke synth, a software modular synthesizer
    Copyright (C) 2021 Ryan Challinor (contact: awwbees@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
//
//  PressureToModwheel.cpp
//  Bespoke
//
//  Created by Ryan Challinor on 1/4/16.
//
//

#include "PressureToModwheel.h"
#include "OpenFrameworksPort.h"
#include "ModularSynth.h"

PressureToModwheel::PressureToModwheel()
{
}

PressureToModwheel::~PressureToModwheel()
{
}

void PressureToModwheel::DrawModule()
{
   if (Minimized() || IsVisible() == false)
      return;
}

void PressureToModwheel::PlayNote(double time, int pitch, int velocity, int voiceIdx, ModulationParameters modulation)
{
   if (mEnabled)
   {
      modulation.modWheel = modulation.pressure;
      modulation.pressure = nullptr;
   }

   PlayNoteOutput(time, pitch, velocity, voiceIdx, modulation);
}

void PressureToModwheel::LoadLayout(const ofxJSONElement& moduleInfo)
{
   mModuleSaveData.LoadString("target", moduleInfo);

   SetUpFromSaveData();
}

void PressureToModwheel::SetUpFromSaveData()
{
   SetUpPatchCables(mModuleSaveData.GetString("target"));
}
