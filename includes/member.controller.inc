<?php
/**
 * @file
 * Entity controller for the Member module.
 */
class MemberController extends EntityAPIControllerExportable {

  /**
   * Overrides EntityAPIController::save().
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {

    // Determine whether the entity is new.
    $primary_key = @$this->entityInfo['entity keys']['id'] ?: 'id';
    $entity->is_new = empty($entity->$primary_key);

    // Set 'created' and 'changed' fields.
    if (empty($entity->created)) {
      $entity->created = REQUEST_TIME;
    }
    $entity->changed = REQUEST_TIME;

    parent::save($entity, $transaction);

  }

}
