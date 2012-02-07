<?php

/**Initialize and ask the triple store to handle the endpoint request
*
* @author Martin Scholz
* 
*/
function wisski_endpoint_serve() {
  
  // fetch the WissKI triple store config
  drupal_load('module', 'wisski_store');
  $config = wisski_store_getObj()->config;
  
  // define which SPARQL verbs may be used by the user
  $config['endpoint_features'] = _wisski_endpoint_access_verbs();

  /* instantiation */
  $ep = ARC2::getStoreEndpoint($config);

  if (!$ep->isSetUp()) {  // should 
      $ep->setUp(); /* create MySQL tables */
  }

  /* request handling */
  $ep->go();

}


/**
* @author Martin Scholz
*/
function wisski_endpoint_admin_settings() {
  
  $form = array();
  $form['wisski_endpoint_read_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Read key'),
    '#description' => t('With this key passed as HTTP argument "key" one gets read access to the triple store (ask, select, describe, construct, dump). This will circumvent the permissions! Leave empty to deactivate.'),
    '#default_value' => variable_get('wisski_endpoint_read_key', ''),
  );
  $form['wisski_endpoint_write_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Write key'),
    '#description' => t('With this key passed as HTTP argument "key" one gets write access to the triple store (load, insert & delete). This will circumvent the permissions! Leave empty to deactivate.'),
    '#default_value' => variable_get('wisski_endpoint_write_key', ''),
  );

  return system_settings_form($form);

}

