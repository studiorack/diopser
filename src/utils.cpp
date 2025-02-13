// Diopser: a phase rotation plugin
// Copyright (C) 2021 Robbert van der Helm
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "utils.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

LambdaAsyncUpdater::LambdaAsyncUpdater(fu2::unique_function<void()> callback)
    : callback(std::move(callback)) {}

void LambdaAsyncUpdater::handleAsyncUpdate() {
    callback();
}

LambdaParameterListener::LambdaParameterListener(
    fu2::unique_function<void(const juce::String&, float)> callback)
    : callback(std::move(callback)) {}

void LambdaParameterListener::parameterChanged(const juce::String& parameterID,
                                               float newValue) {
    callback(parameterID, newValue);
}

#pragma GCC diagnostic pop
