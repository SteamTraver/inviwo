/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2013-2022 Inviwo Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************************/

#pragma once

#include <inviwo/core/common/inviwocoredefine.h>
#include <inviwo/core/processors/progressbar.h>

namespace inviwo {

/** \class ProgressBarOwner
 *
 * Class to support processors owning a ProgressBar.
 * This class allows a progress bar contained within a processor to be visible in the network.
 *
 * \section example Example
 * Example of how to apply it to a processor.
 * @code
 *    class IVW_XXX_API MyProcessor: public Processor, public ProgressBarOwner {
 *    public:
 *        MyProcessor(): Processor(), ProgressBarOwner() {};
 *        // Need to overload serialize/deseralize
 *        virtual void serialize(Serializer& s) const {
 *           Processor::serialize(s);
 *           s.serialize("ProgressBar", getProgressBar());
 *        }
 *        virtual void deserialize(Deserializer& d) {
 *           Processor::deserialize(d);
 *           d.deserialize("ProgressBar", getProgressBar());
 *        }
 *    };
 *
 * @endcode
 * @see ProgressBar
 * @see ProgressBarObservable
 */
class IVW_CORE_API ProgressBarOwner {
public:
    ProgressBarOwner() = default;
    virtual ~ProgressBarOwner() = default;

    ProgressBar& getProgressBar();
    const ProgressBar& getProgressBar() const;

    // Helper function
    inline void updateProgress(float progress);

protected:
    ProgressBar progressBar_;
};

inline void ProgressBarOwner::updateProgress(float progress) {
    progressBar_.updateProgress(progress);
}

}  // namespace inviwo
