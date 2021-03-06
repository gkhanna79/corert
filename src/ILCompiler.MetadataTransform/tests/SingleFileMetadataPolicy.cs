﻿// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

using System;
using ILCompiler.Metadata;
using Internal.TypeSystem;

namespace MetadataTransformTests
{
    struct SingleFileMetadataPolicy : IMetadataPolicy
    {
        public bool GeneratesMetadata(MethodDesc methodDef)
        {
            return true;
        }

        public bool GeneratesMetadata(FieldDesc fieldDef)
        {
            return true;
        }

        public bool GeneratesMetadata(MetadataType typeDef)
        {
            return true;
        }

        public bool IsBlocked(MetadataType typeDef)
        {
            if (typeDef.Name == "ICastable")
                return true;

            return false;
        }
    }
}
