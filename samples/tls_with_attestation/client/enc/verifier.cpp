// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include <openenclave/enclave.h>
#include <stdlib.h>
#include <string>

oe_result_t enclave_identity_verifier_callback(oe_report_t* parsed_report)
{
    printf("enclave_identity_verifier_callback is called with parsed report:\n");

    // report type
    if (parsed_report->type == OE_ENCLAVE_TYPE_SGX)
        printf("parsed_report->type is OE_ENCLAVE_TYPE_SGX\n");
    else
        printf("Unexpected report type\n");

    // Check the enclave's security version
    printf("parsed_report.identity.security_version = %d\n", parsed_report->identity.security_version);
    // if (parsed_report.identity.security_version < 1)
    // {
    // }

    // the unique ID for the enclave
    // For SGX enclaves, this is the MRENCLAVE value
    printf("parsed_report->identity.unique_id :\n");
    for (int i = 0; i < OE_UNIQUE_ID_SIZE; i++)
    {
        printf("0x%0x ", (uint8_t)parsed_report->identity.unique_id[i]);
    }

    // The signer ID for the enclave.
    // For SGX enclaves, this is the MRSIGNER value
    printf("\nparsed_report->identity.signer_id :\n");
    for (int i = 0; i < OE_SIGNER_ID_SIZE; i++)
    {
        printf("0x%0x ", (uint8_t)parsed_report->identity.signer_id[i]);
    }
    
    // The Product ID for the enclave.
    // For SGX enclaves, this is the ISVPRODID value
    printf("\nparsed_report->identity.product_id :\n");
    for (int i = 0; i < OE_PRODUCT_ID_SIZE; i++)
    {
        printf("0x%0x ", (uint8_t)parsed_report->identity.product_id[i]);
    }
    return OE_OK;
}