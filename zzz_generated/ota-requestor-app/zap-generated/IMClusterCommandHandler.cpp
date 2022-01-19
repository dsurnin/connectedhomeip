/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#include <cinttypes>
#include <cstdint>

#include <app-common/zap-generated/af-structs.h>
#include <app-common/zap-generated/callback.h>
#include <app-common/zap-generated/cluster-objects.h>
#include <app-common/zap-generated/ids/Clusters.h>
#include <app-common/zap-generated/ids/Commands.h>
#include <app/CommandHandler.h>
#include <app/InteractionModelEngine.h>
#include <app/util/util.h>
#include <lib/core/CHIPSafeCasts.h>
#include <lib/support/TypeTraits.h>

// Currently we need some work to keep compatible with ember lib.
#include <app/util/ember-compatibility-functions.h>

namespace chip {
namespace app {

// Cluster specific command parsing

namespace Clusters {

namespace Basic {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
    ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                 ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
}

} // namespace Basic

namespace GeneralCommissioning {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
    // When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
    // Any error value TLVUnpackError means we have received an illegal value.
    // The following variables are used for all commands to save code size.
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::ArmFailSafe::Id: {
            Commands::ArmFailSafe::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGeneralCommissioningClusterArmFailSafeCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::CommissioningComplete::Id: {
            Commands::CommissioningComplete::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfGeneralCommissioningClusterCommissioningCompleteCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::SetRegulatoryConfig::Id: {
            Commands::SetRegulatoryConfig::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfGeneralCommissioningClusterSetRegulatoryConfigCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace GeneralCommissioning

namespace NetworkCommissioning {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
    // When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
    // Any error value TLVUnpackError means we have received an illegal value.
    // The following variables are used for all commands to save code size.
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::AddOrUpdateThreadNetwork::Id: {
            Commands::AddOrUpdateThreadNetwork::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfNetworkCommissioningClusterAddOrUpdateThreadNetworkCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::AddOrUpdateWiFiNetwork::Id: {
            Commands::AddOrUpdateWiFiNetwork::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfNetworkCommissioningClusterAddOrUpdateWiFiNetworkCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::ConnectNetwork::Id: {
            Commands::ConnectNetwork::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfNetworkCommissioningClusterConnectNetworkCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::RemoveNetwork::Id: {
            Commands::RemoveNetwork::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfNetworkCommissioningClusterRemoveNetworkCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::ReorderNetwork::Id: {
            Commands::ReorderNetwork::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfNetworkCommissioningClusterReorderNetworkCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::ScanNetworks::Id: {
            Commands::ScanNetworks::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfNetworkCommissioningClusterScanNetworksCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace NetworkCommissioning

namespace OtaSoftwareUpdateProvider {

void DispatchClientCommand(CommandSender * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
    // When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
    // Any error value TLVUnpackError means we have received an illegal value.
    // The following variables are used for all commands to save code size.
    CHIP_ERROR TLVError          = CHIP_NO_ERROR;
    CHIP_ERROR TLVUnpackError    = CHIP_NO_ERROR;
    uint32_t validArgumentCount  = 0;
    uint32_t expectArgumentCount = 0;
    uint32_t currentDecodeTagId  = 0;
    bool wasHandled              = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::ApplyUpdateResponse::Id: {
            expectArgumentCount = 2;
            uint8_t action;
            uint32_t delayedActionTime;
            bool argExists[2];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 2)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    TLVUnpackError = aDataTlv.Get(action);
                    break;
                case 1:
                    TLVUnpackError = aDataTlv.Get(delayedActionTime);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 2 == validArgumentCount)
            {
                wasHandled = emberAfOtaSoftwareUpdateProviderClusterApplyUpdateResponseCallback(
                    aCommandPath.mEndpointId, apCommandObj, action, delayedActionTime);
            }
            break;
        }
        case Commands::QueryImageResponse::Id: {
            expectArgumentCount = 8;
            uint8_t status;
            uint32_t delayedActionTime;
            chip::CharSpan imageURI;
            uint32_t softwareVersion;
            chip::CharSpan softwareVersionString;
            chip::ByteSpan updateToken;
            bool userConsentNeeded;
            chip::ByteSpan metadataForRequestor;
            bool argExists[8];

            memset(argExists, 0, sizeof argExists);

            while ((TLVError = aDataTlv.Next()) == CHIP_NO_ERROR)
            {
                // Since call to aDataTlv.Next() is CHIP_NO_ERROR, the read head always points to an element.
                // Skip this element if it is not a ContextTag, not consider it as an error if other values are valid.
                if (!TLV::IsContextTag(aDataTlv.GetTag()))
                {
                    continue;
                }
                currentDecodeTagId = TLV::TagNumFromTag(aDataTlv.GetTag());
                if (currentDecodeTagId < 8)
                {
                    if (argExists[currentDecodeTagId])
                    {
                        ChipLogProgress(Zcl, "Duplicate TLV tag %" PRIx32, TLV::TagNumFromTag(aDataTlv.GetTag()));
                        TLVUnpackError = CHIP_ERROR_IM_MALFORMED_COMMAND_DATA_ELEMENT;
                        break;
                    }
                    else
                    {
                        argExists[currentDecodeTagId] = true;
                        validArgumentCount++;
                    }
                }
                switch (currentDecodeTagId)
                {
                case 0:
                    TLVUnpackError = aDataTlv.Get(status);
                    break;
                case 1:
                    TLVUnpackError = aDataTlv.Get(delayedActionTime);
                    break;
                case 2:
                    TLVUnpackError = aDataTlv.Get(imageURI);
                    break;
                case 3:
                    TLVUnpackError = aDataTlv.Get(softwareVersion);
                    break;
                case 4:
                    TLVUnpackError = aDataTlv.Get(softwareVersionString);
                    break;
                case 5:
                    TLVUnpackError = aDataTlv.Get(updateToken);
                    break;
                case 6:
                    TLVUnpackError = aDataTlv.Get(userConsentNeeded);
                    break;
                case 7:
                    TLVUnpackError = aDataTlv.Get(metadataForRequestor);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (CHIP_NO_ERROR != TLVUnpackError)
                {
                    break;
                }
            }

            if (CHIP_END_OF_TLV == TLVError)
            {
                // CHIP_END_OF_TLV means we have iterated all items in the structure, which is not a real error.
                TLVError = CHIP_NO_ERROR;
            }

            if (CHIP_NO_ERROR == TLVError && CHIP_NO_ERROR == TLVUnpackError && 8 == validArgumentCount)
            {
                wasHandled = emberAfOtaSoftwareUpdateProviderClusterQueryImageResponseCallback(
                    aCommandPath.mEndpointId, apCommandObj, status, delayedActionTime, imageURI, softwareVersion,
                    softwareVersionString, updateToken, userConsentNeeded, metadataForRequestor);
            }
            break;
        }
        default: {
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || CHIP_NO_ERROR != TLVUnpackError || expectArgumentCount != validArgumentCount || !wasHandled)
    {
        ChipLogProgress(Zcl,
                        "Failed to dispatch command, %" PRIu32 "/%" PRIu32 " arguments parsed, TLVError=%" CHIP_ERROR_FORMAT
                        ", UnpackError=%" CHIP_ERROR_FORMAT " (last decoded tag = %" PRIu32,
                        validArgumentCount, expectArgumentCount, TLVError.Format(), TLVUnpackError.Format(), currentDecodeTagId);
        // A command with no arguments would never write currentDecodeTagId.  If
        // progress logging is also disabled, it would look unused.  Silence that
        // warning.
        UNUSED_VAR(currentDecodeTagId);
    }
}

} // namespace OtaSoftwareUpdateProvider

namespace OtaSoftwareUpdateRequestor {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
    // When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
    // Any error value TLVUnpackError means we have received an illegal value.
    // The following variables are used for all commands to save code size.
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::AnnounceOtaProvider::Id: {
            Commands::AnnounceOtaProvider::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfOtaSoftwareUpdateRequestorClusterAnnounceOtaProviderCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace OtaSoftwareUpdateRequestor

namespace OperationalCredentials {

void DispatchServerCommand(CommandHandler * apCommandObj, const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aDataTlv)
{
    // We are using TLVUnpackError and TLVError here since both of them can be CHIP_END_OF_TLV
    // When TLVError is CHIP_END_OF_TLV, it means we have iterated all of the items, which is not a real error.
    // Any error value TLVUnpackError means we have received an illegal value.
    // The following variables are used for all commands to save code size.
    CHIP_ERROR TLVError = CHIP_NO_ERROR;
    bool wasHandled     = false;
    {
        switch (aCommandPath.mCommandId)
        {
        case Commands::AddNOC::Id: {
            Commands::AddNOC::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterAddNOCCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::AddTrustedRootCertificate::Id: {
            Commands::AddTrustedRootCertificate::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfOperationalCredentialsClusterAddTrustedRootCertificateCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::AttestationRequest::Id: {
            Commands::AttestationRequest::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfOperationalCredentialsClusterAttestationRequestCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::CertificateChainRequest::Id: {
            Commands::CertificateChainRequest::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled =
                    emberAfOperationalCredentialsClusterCertificateChainRequestCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::OpCSRRequest::Id: {
            Commands::OpCSRRequest::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterOpCSRRequestCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::RemoveFabric::Id: {
            Commands::RemoveFabric::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterRemoveFabricCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::RemoveTrustedRootCertificate::Id: {
            Commands::RemoveTrustedRootCertificate::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterRemoveTrustedRootCertificateCallback(apCommandObj, aCommandPath,
                                                                                                      commandData);
            }
            break;
        }
        case Commands::UpdateFabricLabel::Id: {
            Commands::UpdateFabricLabel::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterUpdateFabricLabelCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        case Commands::UpdateNOC::Id: {
            Commands::UpdateNOC::DecodableType commandData;
            TLVError = DataModel::Decode(aDataTlv, commandData);
            if (TLVError == CHIP_NO_ERROR)
            {
                wasHandled = emberAfOperationalCredentialsClusterUpdateNOCCallback(apCommandObj, aCommandPath, commandData);
            }
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCommand);
            ChipLogError(Zcl, "Unknown command " ChipLogFormatMEI " for cluster " ChipLogFormatMEI,
                         ChipLogValueMEI(aCommandPath.mCommandId), ChipLogValueMEI(aCommandPath.mClusterId));
            return;
        }
        }
    }

    if (CHIP_NO_ERROR != TLVError || !wasHandled)
    {
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::InvalidCommand);
        ChipLogProgress(Zcl, "Failed to dispatch command, TLVError=%" CHIP_ERROR_FORMAT, TLVError.Format());
    }
}

} // namespace OperationalCredentials

} // namespace Clusters

void DispatchSingleClusterCommand(const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aReader, CommandHandler * apCommandObj)
{
    Compatibility::SetupEmberAfCommandHandler(apCommandObj, aCommandPath);

    switch (aCommandPath.mClusterId)
    {
    case Clusters::Basic::Id:
        Clusters::Basic::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::GeneralCommissioning::Id:
        Clusters::GeneralCommissioning::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::NetworkCommissioning::Id:
        Clusters::NetworkCommissioning::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::OtaSoftwareUpdateRequestor::Id:
        Clusters::OtaSoftwareUpdateRequestor::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    case Clusters::OperationalCredentials::Id:
        Clusters::OperationalCredentials::DispatchServerCommand(apCommandObj, aCommandPath, aReader);
        break;
    default:
        ChipLogError(Zcl, "Unknown cluster " ChipLogFormatMEI, ChipLogValueMEI(aCommandPath.mClusterId));
        apCommandObj->AddStatus(aCommandPath, Protocols::InteractionModel::Status::UnsupportedCluster);
        break;
    }

    Compatibility::ResetEmberAfObjects();
}

void DispatchSingleClusterResponseCommand(const ConcreteCommandPath & aCommandPath, TLV::TLVReader & aReader,
                                          CommandSender * apCommandObj)
{
    Compatibility::SetupEmberAfCommandSender(apCommandObj, aCommandPath);

    TLV::TLVType dataTlvType;
    SuccessOrExit(aReader.EnterContainer(dataTlvType));
    switch (aCommandPath.mClusterId)
    {
    case Clusters::OtaSoftwareUpdateProvider::Id:
        Clusters::OtaSoftwareUpdateProvider::DispatchClientCommand(apCommandObj, aCommandPath, aReader);
        break;
    default:
        ChipLogError(Zcl, "Unknown cluster " ChipLogFormatMEI, ChipLogValueMEI(aCommandPath.mClusterId));
        break;
    }

exit:
    aReader.ExitContainer(dataTlvType);
    Compatibility::ResetEmberAfObjects();
}

} // namespace app
} // namespace chip
